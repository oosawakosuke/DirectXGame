#include <cpprest/filestream.h>
#include <cpprest/http_client.h>


using namespace utility;             //文字列変換などの一般的なユーティリティ
using namespace web;                 //URIのような共通の機能
using namespace web::http;           //共通のHTTP機能
using namespace web::http::client;   //HTTP クライアントの機能
using namespace concurrency::streams;//非同期ストリーム



//POST
pplx::task<int> Post(const std::wstring &url) {
	return pplx::create_task([=] {
		json::value postData;
		postData[L"name"] = json::value::string(L"ハイパーL4科");

		http_client client(url);
		return client.request(methods::POST, L"",
			postData.serialize(),
			L"application/json"); })
		.then([](http_response response) {
			if (response.status_code() == status_codes::OK) {
				return response.extract_json();
			}})
			.then([](json::value json)
				{ return json[L"serverStatus"].as_integer(); });
}



//GET
template <class T>
pplx::task<T> Get(const std::wstring& url) {
	return pplx::create_task([=] {
		http_client client(url);
		return client.request(methods::GET);
		})
		.then([](http_response response) {
			if (response.status_code() == status_codes::OK)
			{
				return response.extract_json();
			}
			});
}



pplx::task<void> GetTest() {
	return pplx::create_task([] {
		//クライアントの設定
		http_client client(L"http://localhost:3000/faculty");

		//リクエスト送信
		return client.request(methods::GET);
		})
		.then([](http_response response) {
			//ステータスコード判定
			if (response.status_code() == status_codes::OK) {
				//レスポンスbodyを表示
				auto body = response.extract_string();
				setlocale(LC_CTYPE, "");
				std::wcout << body.get().c_str() << std::endl;
			}
			});
}




int main(void) {
	setlocale(LC_CTYPE, "");
	try
	{
		//Get
		auto task = Get<json::value>(L"http://localhost:3000/faculty/");
		const json::value j = task.get();
		auto array = j.as_array();
		for (int i = 0; i < j.size(); i++)
		{
			std::wcout << array[i].at(U("NAME")) << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		printf("Error exception:%s\n", e.what());
	}
	return 0;
}

//int main(void) {
//	setlocale(LC_CTYPE, "");
//	try {
//		//POST
//		auto serverstatusCode =
//			Post(L"http://localhost:3000/faculty/").get();
//
//		if (serverstatusCode == 1 || serverstatusCode == 2) {
//			std::cout << "新規データを追加しました。" << std::endl;
//		}
//	}
//	catch (const std::exception& e) {
//		printf("Error exception:%s/n", e.what());
//	}
//
//	return 0;
//}

//int main(void) {
//	try {
//		GetTest().wait();
//	}catch (const std::exception &e){
//		printf("Error exception:%s/n", e.what());
//	}
//	return 0;
//}
		

