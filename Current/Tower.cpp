
class Tower
{
   public:
      float x;
      float y;
	  float direction;
	  int type;

	  // Towers
	  Tower(float, float, int);
};

Tower::Tower(float x, float y, int type)
{
	this->x = x;  
	this->y = y;
	direction = 0;
	this->type = type;

	switch(type)
	{
	case 1:
		//textures need loading here
		break;
	}

}
