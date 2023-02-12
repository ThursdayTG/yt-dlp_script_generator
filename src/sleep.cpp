#include <chrono>
#include <thread>




void sleep()
{
    // Using directives are used for readability. If you feel inclined to ask "why", my answer is
    // because fuck you, I literally can't read through that shit when it's all in a single line.

    using std::this_thread::sleep_for;
    using std::chrono::milliseconds;
    sleep_for(milliseconds(5000));
}
