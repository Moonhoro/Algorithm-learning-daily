// 输入：abc def sda
/*输出：
 * abc
 * def
 * sda
 */
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (str[j] != ' ' && str[j] != '\0')
        {
            j++;
        }
        for (int k = i; k < j; k++)
        {
            cout << str[k];
        }
    }
    return 0;
}