#pragma once

#include <exception>
#include <string>

class ImageProcessorException : public std::exception {
protected:
    std::string message_;
public:
    ImageProcessorException(const std::string& text)
        : message_("ImageProcessorException: " + text)
    {}

    const char* what() const throw() {
        return message_.c_str();
    }
};

class ParserException : public ImageProcessorException {
public:
    ParserException(const std::string& text)
        : ImageProcessorException("ParserException: " + text)
    {}
};

class IOException : public ImageProcessorException {
public:
    IOException(const std::string& text)
        : ImageProcessorException("IOException: " + text)
    {}
};

class BMPReadingException : public ImageProcessorException {
    public:
        BMPReadingException(const std::string& text)
            : ImageProcessorException("BMPReadingException: " + text)
        {}
    };

class ControllerException : public ImageProcessorException {
    public:
        ControllerException(const std::string& text)
            : ImageProcessorException("ControllerException: " + text)
        {}
    };

class FilterException : public ImageProcessorException {
    public:
        FilterException(const std::string& text)
            : ImageProcessorException("FilterException: " + text)
        {}
    };
