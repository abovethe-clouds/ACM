#include <iostream>
int main()
{
for (int i = 0;i < 10;++i){
for (int j = 0; j < 10 - i - 1;++j){
std::cout <<" ";
}
for (int k = 0; k < 2 * i + 1;++k){
if (k == 0 || k == 2 * i){
std::cout <<"*";
} else {
std::cout <<" ";
}}
std::cout << std::endl;
}
return 0;
}
