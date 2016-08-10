//LLD long long int

LLD power(LLD b, LLD e)
{
	LLD remainder;
	LLD x = 1;
 
		while (e != 0)
		{
			remainder = e % 2;
			e= e/2;

			if (remainder == 1)
				x = (x * b) % m;  //(if x*b overflows use multiply mod(x,b,m))
				b= (b * b) % m; // New base equal b^2 % m
		}
	return x;
}
