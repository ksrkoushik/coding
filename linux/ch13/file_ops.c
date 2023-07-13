#include <stdio.h>

int main()
{
	FILE *input_file = fopen("../../file1.txt", "r");
	FILE *output_file = fopen("output.txt", "w");
	char buffer[1024];
	if(input_file == NULL || output_file == NULL)
	{
		perror("Error opening file");
		return 1;
	}
	while(fgets(buffer, sizeof(buffer), input_file)!= NULL)
	{
		fputs(buffer, output_file);
	}
	fclose(input_file);
	fclose(output_file);
	return 0;
}
