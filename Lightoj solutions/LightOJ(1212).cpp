#include <bits/stdc++.h>
using namespace std;

int main()
{

    int queue_size, operations;
    int test_case, value;
    int case_no = 0;
    string operation;

    scanf("%d", &test_case);

    while (test_case--)
    {

        printf("Case %d:\n", ++case_no);

        scanf("%d%d", &queue_size, &operations);
        deque<int> q;
        deque<int> :: iterator it;

        for (int i = 1; i <= operations; i++)
        {
            cin >> operation;

            if (operation == "pushLeft")
            {

                cin >> value;

                if (q.size() == queue_size)
                    printf("The queue is full\n");
                else
                {

                    printf("Pushed in left: %d\n", value);
                    q.push_front(value);
                }
            }
            else if (operation == "pushRight")
            {

                cin >> value;

                if (q.size() == queue_size)
                    printf("The queue is full\n");
                else
                {

                    printf("Pushed in right: %d\n", value);
                    q.push_back(value);
                }
            }
            else if (operation == "popLeft")
            {

                if (q.size() == 0)
                    printf("The queue is empty\n");
                else
                {
                    it = q.begin();
                    printf("Popped from left: %d\n",*it);
                    q.pop_front();
                }
            }
            else if (operation == "popRight")
            {
                if (q.size() == 0)
                    printf("The queue is empty\n");
                else
                {
                    it = q.end();
                    --it;
                    printf("Popped from right: %d\n", *it);
                    q.pop_back();
                }
            }
        }
    }
    return 0;
}
