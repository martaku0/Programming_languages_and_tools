#include <iostream>
#include <httplib.h>

int main() {
    // Initialisation of a client pointing to local server
    httplib::Client cli("localhost", 8000);

    std::cout << "--- Test GET /api/status ---" << std::endl;
    if (auto res = cli.Get("/api/status")) {
        // Checking the HTTP status code (e.g., 200 OK)
        if (res->status == 200) {
            std::cout << "Status: " << res->status << "\n";
            std::cout << "Response body: " << res->body << "\n";
        }
    } else {
        std::cerr << "Connection error: " << to_string(res.error()) << "\n";
    }

    std::cout << "\n--- Test GET /user/123 ---" << std::endl;
    if (auto res = cli.Get("/user/123")) {
        std::cout << "Response: " << res->body << "\n";
    }

    std::cout << "\n--- Test POST /data ---" << std::endl;
    // Sending a POST request with a simple text body (payload) and the appropriate Content-Type
    std::string payload = "This is a test message from the client";
    if (auto res = cli.Post("/data", payload, "text/plain")) {
        std::cout << "Status: " << res->status << "\n";
        std::cout << "Response from server: " << res->body << "\n";
    }

    return 0;
}