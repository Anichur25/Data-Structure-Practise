#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main()
{


    int case_no = 0;
    int case_numbers;


    scanf("%d", &case_numbers);

    while (case_numbers--)
    {

        stack<string> backward, forward;
        string command, url, query_url;
        string current_page = "http://www.lightoj.com/";
        printf("Case %d:\n",++case_no);

        while (true)
        {

            cin >> command;

            if (command == "VISIT")
            {

                cin >> url;
                backward.push(current_page);
                current_page = url;

                while (forward.size())
                {
                    forward.pop();
                }

                query_url = url;
            }
            else if (command == "BACK")
            {
                if (!backward.size())
                {

                    query_url = "Ignored";
                }
                else
                {
                    forward.push(current_page);
                    current_page = backward.top();
                    backward.pop();
                    query_url = current_page;
                }
            }

            else if (command == "FORWARD")
            {

                if (!forward.size())
                {

                    query_url = "Ignored";
                }
                else
                {
                    backward.push(current_page);
                    current_page = forward.top();
                    forward.pop();
                    query_url = current_page;
                }
            }
            else
                break;

          cout << query_url << endl;
        }


    }

    return 0;
}
