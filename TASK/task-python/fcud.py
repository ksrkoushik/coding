import pika

connection_parameters = pika.ConnectionParameters('localhost')

connection = pika.BlockingConnection(connection_parameters)

channel = connection.channel()

channel.queue_declare('fcud.input', durable=True)

message = """<Message>
   <Command>Create</Command>
   <FileName>Xyz.txt</FileName>
   <Content>Happy New Year\n</Content>
</Message>"""

channel.basic_publish(exchange='', routing_key='fcud.input', body=message)

print(f"Sent message: {message}")

connection.close()
