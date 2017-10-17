// Copyright 2017 Andy Taylor

#include "framework/Renderer.h"

Renderer::Renderer(const std::string &vertFile, const std::string &fragFile) {
    GLuint vid = loadShader(vertFile, GL_VERTEX_SHADER);
    GLuint fid = loadShader(fragFile, GL_FRAGMENT_SHADER);
    
    programID = glCreateProgram();
    glAttachShader(programID, vid);
    glAttachShader(programID, fid);
    
    glBindFragDataLocation(programID, 0, "outColor");
    glLinkProgram(programID);
    
    glDeleteShader(vid);
    glDeleteShader(fid);
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    glGenBuffers(1, &vbo);
    posLocation = glGetAttribLocation(programID, "position");
    
    GLfloat vertices[] = {
         0.0f,  0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f
    };
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glEnableVertexAttribArray(posLocation);
}

void Renderer::activate() {
    glUseProgram(programID);
}

GLuint Renderer::loadShader(const std::string &fileName, GLenum type) {
    const std::string source = readFile(fileName);
    int32_t size = source.length();
    
    GLuint id = glCreateShader(type);
    
    char* src = const_cast<char*>(source.c_str());
    glShaderSource(id, 1, &src, &size);
    glCompileShader(id);
    
    int compile_ok = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compile_ok);
    if (compile_ok == 0) {
        std::cerr << "Shader failed to compile: " << std::endl;
        printShaderCompilationError(id);
        return 0;
    }

    return id;
}

const std::string Renderer::readFile(const std::string &fileName) {
    std::ifstream f(fileName);
    std::stringstream buf;
    
    buf << f.rdbuf();
    
    return buf.str();
}

void Renderer::printShaderCompilationError(GLuint id) {
    int logLength;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);

    char* shaderInfoLog = new char[logLength];
    glGetShaderInfoLog(id, logLength, &logLength, shaderInfoLog);

    std::cerr << shaderInfoLog << std::endl;
}

