import pika
import xml.etree.ElementTree as ET
import os

# Ensure the directory /usr/applications/fcud/files/ exists with read/write permissions
FCUD_PATH = "/usr/applications/fcud/files/"
os.makedirs(FCUD_PATH, exist_ok=True)
os.chmod(FCUD_PATH, 0o777)  # Set read/write permissions for all users

def on_message_received(ch, method, properties, body):
    try:
        # Parse XML message
        root = ET.fromstring(body)
        
        # Extract command, filename, and content from XML elements
        command = root.find('Command').text
        filename = root.find('FileName').text
        content = root.find('Content').text if root.find('Content') is not None else ""
        
        # Perform message validation
        if command.lower() not in ['create', 'delete', 'update']:
            print(f"Invalid command: {command}. Skipping message...")
            return
        
        if not filename:
            print("Missing FileName in message. Skipping message...")
            return

        # Process message based on command
        if command.lower() == "create":
            # Create or update the file with filename and content
            file_path = os.path.join(FCUD_PATH, filename)
            with open(file_path, 'w') as file:
                file.write(content)
            print(f"File '{filename}' created/updated with content: {content}")

        if command.lower() == "update":
            # Create or update the file with filename and content
            file_path = os.path.join(FCUD_PATH, filename)
            with open(file_path, 'a') as file:
                file.write(content)
            print(f"File '{filename}' created/updated with content: {content}")
        
        elif command.lower() == "delete":
            # Delete the file with filename
            file_path = os.path.join(FCUD_PATH, filename)
            if os.path.exists(file_path):
                os.remove(file_path)
                print(f"File '{filename}' deleted successfully")
            else:
                print(f"File '{filename}' does not exist")
    except Exception as e:
        print(f"Error processing message: {e}")

# Connect to RabbitMQ server
connection_parameters = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(connection_parameters)
channel = connection.channel()

# Declare the queue
channel.queue_declare('fcud.input', durable=True)

# Consume messages from the queue
channel.basic_consume(queue='fcud.input', auto_ack=True, on_message_callback=on_message_received)

print("Started consuming messages...")
channel.start_consuming()
