/*
 * Easing.h
 *
 *  Created on: 7 oct. 2017
 *      Author: valen
 */

#ifndef SRC_MATH_EASING_H_
#define SRC_MATH_EASING_H_

#include <cmath>

#define PI 3.1415926545

class Easing
{
public:
	static float Linear(float k)
	{
		return k;
	}

	static float Interpolate(float x, float prevX, float t)
	{
		return (x - prevX) * t + prevX;
	}

	class Quadratic
	{
	public:
		static float In(float k)
		{
			return k * k;
		}

		static float Out(float k)
		{
			return k * (2.0F - k);
		}

		static float InOut(float k)
		{
			return k < 0.5 ? 2 * k * k : k * (4 - 2 * k) - 1;
		}
	};

	class Cubic
	{
	public:
		static float In(float k)
		{
			return k * k * k;
		}

		static float Out(float k)
		{
			return 1 + (--k) * k * k;
		}

		static float InOut(float k)
		{
			if ((k *= 2.0F) < 1.0F)
				return 0.5F * k * k * k;
			return 0.5F * ((k -= 2.0F) * k * k + 2.0F);
		}
	};

	class Quartic
	{
	public:
		static float In(float k)
		{
			return k * k * k * k;
		}

		static float Out(float k)
		{
			return 1.0F - ((k -= 1.0F) * k * k * k);
		}

		static float InOut(float k)
		{
			if ((k *= 2.0F) < 1.0F)
				return 0.5F * k * k * k * k;
			return -0.5F * ((k -= 2.0F) * k * k * k - 2.0F);
		}
	};

	class Quintic
	{
	public:
		static float In(float k)
		{
			return k * k * k * k * k;
		}

		static float Out(float k)
		{
			return 1.0F + ((k -= 1.0F) * k * k * k * k);
		}

		static float InOut(float k)
		{
			if ((k *= 2.0F) < 1.0F)
				return 0.5F * k * k * k * k * k;
			return 0.5F * ((k -= 2.0F) * k * k * k * k + 2.0F);
		}
	};

	class Sinusoidal
	{
	public:
		static float In(float k)
		{
			return sin( PI / 2.0F * k );
		}

		static float Out(float k)
		{
			return sin(k * PI / 2.0F);
		}

		static float InOut(float k)
		{
			return 0.5F * (1.0F - cos(PI * k));
		}
	};

	class Exponential
	{
	public:
		static float In(float k)
		{
			return k == 0.0F ? 0.0F : pow(1024.0F, k - 1.0F);
		}

		static float Out(float k)
		{
			return k == 1.0F ? 1.0F : 1.0F - pow(2.0F, -10.0F * k);
		}

		static float InOut(float k)
		{
			if (k == 0.0F)
				return 0.0F;
			if (k == 1.0F)
				return 1.0F;
			if ((k *= 2.0F) < 1.0F)
				return 0.5F * pow(1024.0F, k - 1.0F);
			return 0.5F * (-pow(2.0F, -10.0F * (k - 1.0F)) + 2.0F);
		}
	};

	class Circular
	{
	public:
		static float In(float k)
		{
			return 1.0F - sqrt(1.0F - k * k);
		}

		static float Out(float k)
		{
			return sqrt(1.0F - ((k -= 1.0F) * k));
		}

		static float InOut(float k)
		{
			if ((k *= 2.0F) < 1.0F)
				return -0.5F * (sqrt(1.0F - k * k) - 1);
			return 0.5F * (sqrt(1.0F - (k -= 2.0F) * k) + 1.0F);
		}
	};

	class Elastic
	{
	public:
		static float In(float k)
		{
			if (k == 0)
				return 0;
			if (k == 1)
				return 1;
			return -pow(2.0F, 10.0F * (k -= 1.0F)) * sin((k - 1.0F) * (2.0F * PI) / 0.4f);
		}

		static float Out(float k)
		{
			if (k == 0)
				return 0;
			if (k == 1)
				return 1;
			return pow(2.0F, -10.0F * k) * sin((k - 1.0F) * (2.0F * PI) / 0.4f) + 1.0F;
		}

		static float InOut(float k)
		{
			if ((k *= 2.0F) < 1.0F)
				return -0.5F * pow(2.0F, 10.0F * (k -= 1.0F)) * sin((k - 1.0F) * (2.0F * PI) / 0.4f);
			return pow(2.0F, -10.0F * (k -= 1.0F)) * sin((k - 1.0F) * (2.0F * PI) / 0.4f) * 0.5F + 1.0F;
		}
	};

	class Back
	{
	public:
		#define BackS 1.70158f
		#define BackS2 2.5949095f

		static float In(float k)
		{
			return k * k * ((BackS + 1.0F) * k - BackS);
		}

		static float Out(float k)
		{
			return (k -= 1.0F) * k * ((BackS + 1.0F) * k + BackS) + 1.0F;
		}

		static float InOut(float k)
		{
			if ((k *= 2.0F) < 1.0F)
				return 0.5F * (k * k * ((BackS2 + 1.0F) * k - BackS2));
			return 0.5F * ((k -= 2.0F) * k * ((BackS2 + 1.0F) * k + BackS2) + 2.0F);
		}
	};

	class Bounce
	{
	public:
		static float In(float k)
		{
			return 1.0F - Out(1.0F - k);
		}

		static float Out(float k)
		{
			if (k < (1.0F / 2.75f))
			{
				return 7.5625f * k * k;
			}
			else if (k < (2.0F / 2.75f))
			{
				return 7.5625f * (k -= (1.5f / 2.75f)) * k + 0.75f;
			}
			else if (k < (2.5f / 2.75f))
			{
				return 7.5625f * (k -= (2.25f / 2.75f)) * k + 0.9375f;
			}
			else
			{
				return 7.5625f * (k -= (2.625f / 2.75f)) * k + 0.984375f;
			}
		}

		static float InOut(float k)
		{
			if (k < 0.5F)
				return In(k * 2.0F) * 0.5F;
			return Out(k * 2.0F - 1.0F) * 0.5F + 0.5F;
		}
	};
};

#endif /* SRC_MATH_EASING_H_ */
