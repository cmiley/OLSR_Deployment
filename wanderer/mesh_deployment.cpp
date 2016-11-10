
static const int MS_MODIFIER = 1000000;
static const float THRESHOLD = 2.5;
static const float FULL_ROTATION = 360.0;
static const float HALF_ROTATION = 180.0;

bool move_cartesian();
bool move_angular();
bool stop_bot();
int move_forward();
int check_link_quality();
bool deploy_node();
void rotate( float angle );

bool move_cartesian( double x_dist, double y_dist, bool debugFlag )
{
	if( (x_dist < 0) || (y_dist < 0) )
	{
		if( debugFlag )
		{
			printS( "Negative value for x or y\n" );
		}
	}
	
}

bool move_angular( double radius, double angle )
{
	double dist_traveled = 0.0;

	if( radius < 0 )
	{
		angle += HALF_ROTATION;
		radius *= -1.0;
	}

	if( angle > FULL_ROTATION )
	{
		angle = angle - ( (int) angle/FULL_ROTATION ) * FULL_ROTATION;
	}
	else if( angle < (-1)*FULL_ROTATION )
	{
		angle = (( (int) angle/FULL_ROTATION + 1 ) * FULL_ROTATION) + angle;
	}

	while( front_dist > 0.1 && radius > dist_traveled )
	{
		rotate( angle );
		lvel = 1;
	}
}

bool stop_bot()
{
	// forward distance in meters
	float distForward = .3;
	float angle = HALF_ROTATION;
	bool flag = false;

	if( move_angular( distForward, angle ) )
	{
		flag = true;
	}

	rvel = lvel = 0;

	return flag;
}

int move_forward()
{
	struct timeval refTime;

	lvel = 1;
	while( timePassed( refTime ) < seconds * MS_MODIFIER );
	lvel = 0;
}

int check_link_quality()
{
	// make sure OLSR json output plugin is enabled
	// fetch data from OLSR server (http request)
	// parse data
}

bool deploy_node()
{
	while( check_link_quality() < THRESHOLD )
	{
		move_forward();
	}
	stop_bot();

	if( check_link_quality < THRESHOLD - OFFSET )
	{
		return true;
	}
	else return false;
}

void rotate( angle )
{

}