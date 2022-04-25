#ifndef _SHADERUTILS_H_
#define _SHADERUTILS_H_

#include <cstdio>
#include <cstring>
#include <iostream>
class ShaderUtils
{
public:
	static const char* GetDefaultVertesShader()
	{
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

		return vertexShaderSource;
	}
	static const char* GenereFragmentShaderWithColor(float r, float g, float b)
	{
		const char* firstPart =
			"#version 330 core\n"
			"out vec4 FdfragColor;\n"
			"void main()\n"
			"{\n"
			"	FdfragColor = vec4(";

		const char* rCharacterPointer = FloatToCharacterPointer(r);
		const char* gCharacterPointer = FloatToCharacterPointer(g);
		const char* bCharacterPointer = FloatToCharacterPointer(b);

		const char* endPart = 
			", 1.0f)\n;"
			"}\0";

		int length = strlen(firstPart) 
				  + strlen(rCharacterPointer) + strlen(",") //  red value length + one comma
			      + strlen(gCharacterPointer) + strlen(",") //  value length + one comma
				  + strlen(bCharacterPointer) //  value length
				  + strlen(endPart) + 1;

		char* finalBuffer = new char[length];
		strcpy_s(finalBuffer, length , firstPart);
		strcat_s(finalBuffer, length, rCharacterPointer);
		strcat_s(finalBuffer, length, ",");
		strcat_s(finalBuffer, length, gCharacterPointer);
		strcat_s(finalBuffer, length, ",");
		strcat_s(finalBuffer, length, bCharacterPointer);
		strcat_s(finalBuffer, length, endPart);

		return finalBuffer;
	}

	static const char* FloatToCharacterPointer(float value)
	{
		char buffer[64];
		int length = snprintf(buffer, sizeof(buffer), "%f", value);
		if (length <= 0)
			return "";

		char* bufferPointer = new char[length];
		length = snprintf(bufferPointer, sizeof(char) * length, "%f", value);

		return bufferPointer;
	}
};

#endif // !_SHADERUTILS_H_


