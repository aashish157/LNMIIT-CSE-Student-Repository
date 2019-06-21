#include <stdio.h>

int main()
{
	char str[20];
	scanf( "%s", str );

	int maxX=0, maxY=0;

	scanf( "%d %d", &maxX, &maxY );
	int asd;
	scanf( "%d", &asd );
	
	int size = maxX * maxY;
	
	int f_red[500], f_green[500], f_blue[500];

	for( int i=0 ; i<500 ; i++ )
	{
		f_red[i]=0;
		f_green[i]=0;
		f_blue[i]=0;
	}	


	for( int i=0 ; i< size ; i++ )
	{
		int tmpR, tmpG, tmpB;
		scanf( "%d", &tmpR );
		scanf( "%d", &tmpG );
		scanf( "%d", &tmpB );

		f_red[ tmpR ]++;
		f_green[ tmpG ]++;
		f_blue[ tmpB ]++;
	}


	//printing
	puts( "RED" );
	for( int i=0 ; i<=255 ; i++ )
	{
		printf( "%d %d\n",i, f_red[i] );
	}
		
	puts( "GREEN" );
	for( int i=0 ; i<=255 ; i++ )
	{
		printf( "%d %d\n",i, f_green[i] );
	}

	puts( "BLUE" );
	for( int i=0 ; i<=255 ; i++ )
	{
		printf( "%d %d\n",i, f_blue[i] );
	}

	return 0;
}

