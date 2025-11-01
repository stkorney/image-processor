#pragma once

#include <exception>
#include <string>

class ImageProcessorException : public std::exception {
protected:
    std::string message_;

public:
    explicit ImageProcessorException(const std::string& text) : message_("ImageProcessorException: " + text) {
    }

    const char* what() const throw() override {
        return message_.c_str();
    }
};

class ParserException : public ImageProcessorException {
public:
    explicit ParserException(const std::string& text) : ImageProcessorException("ParserException: " + text) {
    }
};

class IOException : public ImageProcessorException {
public:
    explicit IOException(const std::string& text) : ImageProcessorException("IOException: " + text) {
    }
};

class BMPReadingException : public ImageProcessorException {
public:
    explicit BMPReadingException(const std::string& text) : ImageProcessorException("BMPReadingException: " + text) {
    }
};

class ControllerException : public ImageProcessorException {
public:
    explicit ControllerException(const std::string& text) : ImageProcessorException("ControllerException: " + text) {
    }
};

class FilterException : public ImageProcessorException {
public:
    explicit FilterException(const std::string& text) : ImageProcessorException("FilterException: " + text) {
    }
};
