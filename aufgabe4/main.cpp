#include <iostream>

class AA {
	public:
		AA(int val) {
			this->val = val;
		};
		void display() {
			std::cout << val << std::endl;
		}
	protected:
		int val;
};


class BB : public AA {
	public:
		BB(char val):AA(val) {};
	private:
		char val;
};

class CC : public AA {
	public:
		CC(float val):AA(val) {};
	private:
		float val;
};

int main() {

	AA a(44);
	BB b('a');
	CC c(1.87);

	a.display();
	b.display();
	c.display();

	return 0;
}