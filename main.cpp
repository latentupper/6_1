#include <iostream>

//основной код
template<typename Function, typename... Types>
void apply(Function func, Types... args) {
    func(args...);
}

//произвольная функция
bool ExistTriangle(double a, double b, double c) {
    bool res = true;
    if((a<=0) || (b<=0) || (c<=0)) {
        res = false;
    }
    //считая вырожденный случай за существование
    if(((a+b)<c) || ((a+c)<b) || ((b+c)<a)) {
        res = false;
    }
    //наглядная проверка
    std::cout << std::boolalpha << res << std::endl;
    return res;
}

int main() {
    apply(ExistTriangle, 3, 4, 5);
    return 0;
}
