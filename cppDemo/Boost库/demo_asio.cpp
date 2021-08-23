#include<iostream>
#include<boost/asio.hpp>
#include<boost/asio/steady_timer.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>
void callback(const boost::system::error_code&)
{
	std::cout << "hello ,world!1" << std:: endl;
}
void callback2(const boost::system::error_code&)
{
	std::cout << "hello ,world!2" << std::endl;
}

void Print(const boost::system::error_code &,
		   boost::asio::deadline_timer * t,int *count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		++(*count);
		t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
		t->async_wait([t, count](const auto& error) {Print(error, t, count); });
	}
}
int main()
{
	boost::asio::io_service io;
	int count = 0;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
	t.async_wait([&t, &count](const auto& error) {Print(error, &t, &count); });
	io.run();
	std::cout << "Finish..." << std::endl;
}

/*
	//同步调用方式
	boost::asio::io_service io;
	boost::asio::deadline_timer t{ io,boost::posix_time::seconds(5) };
	t.wait();
	std::cout << "hello ,world!" << std::endl;
	*/
	//异步方式
	/*
	boost::asio::io_service io;
	boost::asio::steady_timer st(io);
	st.expires_from_now(std::chrono::seconds(5));
	st.wait();
	std::cout << "Finish!" << std::endl;
	return 0;
	*/