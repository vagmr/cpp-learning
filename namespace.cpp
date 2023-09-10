#include <iostream>
namespace xg
{
    namespace fuc
    {
        void prtHello()
        {
            std::cout << "hello world" << std::endl;
        }
    }
} // namespace xg
int main()
{
    using namespace xg;
    using fuc::prtHello;
    namespace a = fuc; //  namespace a = fuc::prtHello
    using std::cout;
    prtHello();
    cout << "hello world";
}