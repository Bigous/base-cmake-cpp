#include <chrono>
#include <ctime>
#include <format>
#include <iostream>
#include <locale>

int main( int argc, char *argv[] )
{
	auto loc = std::locale( "" );
	std::locale::global( loc );
	std::cout.imbue( loc );

	const std::chrono::zoned_time cur_time{ std::chrono::current_zone(), std::chrono::system_clock::now() };

	auto str_date = std::format( std::locale( "pt-BR" ), "{0:%Ex} {0:%T %z}", cur_time );

	std::cout << str_date << std::endl << cur_time << std::endl;
	return 0;
}