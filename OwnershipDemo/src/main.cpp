#include "FrameBuffer.h"

int main() {
	// RAII‚Æmove‚Ì—‰ğ(unique_ptr)
	std::cout << "/////RAII‚Æmove‚Ì‰‰K//////\n";
	FrameBuffer fb1(10);
	fb1.fill(42);
	fb1.print();

	FrameBuffer fb2(20);
	fb2.fill(7);
	fb2.print();

	fb2 = std::move(fb1);
	fb2.print();

	// shared_ptr, weak_ptr‚Ì—‰ğ
	std::cout << "/////shared_ptr, weak_ptr‰‰K/////\n";
	std::shared_ptr<int> sp1 = std::make_shared<int>(100);
	std::weak_ptr<int> wp = sp1;

	std::cout << "use_count after weak_ptr : " << sp1.use_count() << "\n";

	std::shared_ptr<int> sp2 = sp1;
	std::cout << "use_count after sp2 : " << sp2.use_count() << "\n";

	{
		std::shared_ptr<int> sp3 = sp2;
		std::cout << "use_count after sp3 : " << sp1.use_count() << "\n";
	}

	std::cout << "use_count after sp3 scope : " << sp1.use_count() << "\n";

}