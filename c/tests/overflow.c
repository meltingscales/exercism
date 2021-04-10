int main(){

    unsigned char foo = 0;

    foo--; //underflow

    if(foo == ((unsigned char)-1))
    {
        printf("-1 == 0xff if it's an unsigned char.\n");
    }

    printf("foo = %d",foo);

}