#include<iostream>
#include<uwebsockets/App.h>

#include<string>
using namespace std;
using namespace uWS;

int main()
{
	/*string ur;
	
	App().get("/text=", [&](HttpResponse<false>* res, HttpRequest* req)
		{
			ur = req->getUrl();
			if (ur == "/text=")
				res->writeHeader("Content-Type", "text/html; charset=utf-8")->end("text");
			if (ur == "/suka")
				res->end("da da");
			else
				res->end("error");
			auto query = req->getQuery();
			cout << query;
			res->end("prinyal");

			
		}

	).listen("127.0.0.1", 8080, [&](auto* token) 
		{
			if (token)
				cout << "connect\n";

		}).run();
	std::cout << "Failed to listen to port " << 8080 << std::endl;*/

	uWS::App app;

	app.get("/text", [](HttpResponse<false>* res, HttpRequest* req)
		{
			res->end("this text");
			auto query = req->getQuery();
			cout << query;
		}
	);
	app.post("/txt?txt=textExample", [](HttpResponse<false>* res, HttpRequest* req)
		{
			
		}
	);
	app.listen("127.0.0.1", 8080, [](auto* token) 
		{
			if (token)
				cout << "connect\n";
		});
	app.run();
	return 0;
}