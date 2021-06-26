#include <iostream>

#include "Session.h"

//#include <QPcbWindow.h>
//
//#include <QApplication>

int main(int argc, char *argv[]) {

    Session session;
//    auto x = session.GetStorage()._left._vertices.back();
//    std::cout << "(" << x.x <<", " << x.y <<")\n";
    std::cout << "That's all!" << std::endl;
    return Session::Start(argc, argv);

    return 0;
}
