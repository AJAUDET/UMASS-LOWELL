
int bin_search(int key)
{
    int found = 0;
    int j = 1;
    int min = 0;
    int max = N - 1;
    while (found == 0)
    {
        if (min > max)
        {
            break;
        }
        else
        {
            j = floor((min + max) / 2);
            if (key == A[j])
            {
                found = 1;
            }
            else
            {
                if (key < A[j])
                {
                    max = j - 1;
                }
                else
                {
                    min = j + 1;
                }
            }
        }
    }
    return j;
}

int bin_search(int key)
{
    int found = 0;
    int j = 1;
    int min = 0;
    int max = N - 1;

LOOP:
    if(found != 0) goto DONE;
    
    if(min <= max) goto DONE;
    j = floor((min + max) / 2);
    if(key != A[j]) goto ELSE;
    found = 1;


ELSE:
    if(key >= A[j]) goto ELSE2;
    max = j - 1;
    goto LOOP;
ELSE2:
    max = j + 1;
    goto LOOP;


DONE:
    return j;
}