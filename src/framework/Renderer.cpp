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
    
    loc_pos = glGetAttribLocation(programID, "position");
    loc_model = glGetAttribLocation(programID, "M");
    loc_view = glGetAttribLocation(programID, "V");
    loc_proj = glGetAttribLocation(programID, "P");
}

void Renderer::loadMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) {
    glUniformMatrix4fv(loc_model, 1, GL_FALSE, glm::value_ptr(m));
    glUniformMatrix4fv(loc_view, 1, GL_FALSE, glm::value_ptr(v));
    glUniformMatrix4fv(loc_proj, 1, GL_FALSE, glm::value_ptr(p));
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

