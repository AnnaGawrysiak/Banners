#pragma once

class Test
{
private:
    Test();
    static Test* wsk;

public:
    void operator = (const Test&) = delete;
    Test(const Test&) = delete;

    static Test* get_instance();

   // bool test1();

    //bool test2();

    void run();

};
