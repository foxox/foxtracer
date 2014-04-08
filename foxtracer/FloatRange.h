
struct FloatRange
{
	float low;
	float high;

	FloatRange(float _low, float _high)
	{
		this->low = _low;
		this->high = _high;
	}

	~FloatRange() {}
};