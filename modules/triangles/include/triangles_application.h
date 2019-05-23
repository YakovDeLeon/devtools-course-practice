// Copyright 2019 Valiullin Damir

#ifndef MODULES_TRIANGLES_INCLUDE_TRIANGLES_APPLICATION_H_
#define MODULES_TRIANGLES_INCLUDE_TRIANGLES_APPLICATION_H_

#include <string>

class TrianglesApp {
 public:
    TrianglesApp();
    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     typedef struct {
         double x1;
         double y1;
         double x2;
         double y2;
         double x3;
         double y3;
         char operation;
     } Arguments;
};

#endif  // MODULES_TRIANGLES_INCLUDE_TRIANGLES_APPLICATION_H_
