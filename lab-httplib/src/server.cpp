
#include <iostream>
#include <httplib.h>

int main() {
   
  // HTTP
  httplib::Server svr;

  // Basic GET request
  svr.Get("/", [](const httplib::Request &, httplib::Response &res) {
    res.set_content("Hello World!", "text/plain");
  });

  // GET returning JSON format
    svr.Get("/api/status", [](const httplib::Request &, httplib::Response &res) {
        std::string json_response = R"({"status": "ok", "version": "1.0"})";
        res.set_content(json_response, "application/json");
    });

    // GET with parameters in the URL (regular expressions)
    // E.g. request: /user/123
    svr.Get(R"(/user/(\d+))", [](const httplib::Request &req, httplib::Response &res) {
        // req.matches[1] contains the matched substring from the first set of parentheses in the regex
        std::string user_id = req.matches[1];
        res.set_content("Fetching data for user with ID: " + user_id, "text/plain");
    });

    // Handling a POST request with a body
    svr.Post("/data", [](const httplib::Request &req, httplib::Response &res) {
        std::string request_body = req.body;
        std::cout << "Received POST: " << request_body << std::endl;
        
        res.set_content("The data has been successfully received!", "text/plain");
    });

  std::cout << "The server runs on port 8000." << std::endl;

  svr.listen("0.0.0.0", 8000);

}
