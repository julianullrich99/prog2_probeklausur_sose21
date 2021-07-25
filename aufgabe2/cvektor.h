#ifndef CVEKTOR_H
#define CVEKTOR_H

class CVektor {
	public:
		CVektor();
		CVektor(CVektor*);
		CVektor(int anz, float wert);
		~CVektor();
		float &operator[](int x);
		void operator=(CVektor vector);
		CVektor operator+(CVektor &vector);
		void operator+=(CVektor &vector);
		int length();
		void display();

	private:
		int n;
		float* f;
};




#endif