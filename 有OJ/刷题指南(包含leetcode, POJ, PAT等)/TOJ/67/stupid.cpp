int main()
{
    initialize();
    
    for(int i = 1; i < 1000000; i++)
	if(throw_egg(i) == 0)
	    answer(i - 1);

    return 0;
}
