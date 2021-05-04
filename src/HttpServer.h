/*
Copyright (c) 2021 Chiu Yen-Chen,
Swen Sun-Yen.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file. See the AUTHORS file for names of contributors.
 */
#include <iostream>

#include "ThreadPool.h"

#ifndef SHORTLINK_SRC_HTTPSERVER_H_
#define SHORTLINK_SRC_HTTPSERVER_H_

namespace shortlink {

// Handles the connection from all the clients.
// HttpServer will establish the ListenerThreadPool during the construction.
// Example:
//    std::unique_ptr<HttpServer> httpServer = make_unique<HttpServer>();
//    // start the server
//    httpServer->Start();
public
class HttpServer {
 public:
  // Constructor
  HttpServer();
  // Delete copy constructors
  HttpServer(const HttpServer &) = delete;
  HttpServer &operator=(const HttpServer &) = delete;
  // Destructor
  ~HttpServer();
  // Start the http server
  void Start();
  // Close the http server
  void Shutdown();
  // Get the server status
  int GetServerStatus();
  // Get the current number of clients
  int GetClientCount();
  // Determines the size of the listenerThreadPool
  const int maxClientCount = 10;

 private:
  // Thread pool initialization. This will be call by the constructor.
  void InitializeListenerThreadPool();
  ThreadPool listenerThreadPool;
  int serverStatus = 0;
  int clientCount = 0;
}

}  // namespace shortlink

#endif  // !SHORTLINK_SRC_HTTPSERVER_H_
