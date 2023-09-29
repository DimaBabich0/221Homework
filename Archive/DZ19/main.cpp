#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    string path;
    cout << "Enter path to html file: ";
    cin >> path;

    ifstream in;
    in.open(path, ios::in);

    if (in)
    {
        int count = 0;
        char ch;
        bool isTagOpen = false;

        //because file reaches the end and makes another loop circle, while nothing is
        //written in "ch", that causes +1 error, so I changed loop condition to "in.get(ch)"
        while (in.get(ch))
        {
            if (ch == '<' && !isTagOpen)
                isTagOpen = true;
            else if (ch == '>' && isTagOpen)
                isTagOpen = false;
            else if (ch == '>' && !isTagOpen)
                count++;
            else if (ch == '<' && isTagOpen)
                count++;
        };

        cout << "Count of count: " << count << endl;
        in.close();
    }
    else
        cout << "Could not open the file" << endl;
}