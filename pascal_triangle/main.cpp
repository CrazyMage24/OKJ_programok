    #include <iostream>
    using namespace std;
    int main()
    {
        int rows;
        int start = 1;
        int space = 1;
        cout << "Enter number of rows: ";
        cin >> rows;
        int i = rows;
        for(space = 1; space <= rows-i; space++)
        {
            cout <<"  ";
        }
        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
            {
                start = 1;
            }
            else
            {
                start = start*(i-j+1)/j;
            }
            cout << start << "   ";
        }
        cout << endl;
        return 0;
    }
