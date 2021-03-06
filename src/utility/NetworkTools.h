//
// Created by tag on 03/01/17.
//

#pragma once


class NetworkTools
{
public:
    /**
     * Initialize server connection
     * @param argc
     * @param argv : message [port]
     * @return success
     */
     static int initServer(int argc, char *argv[]);

    /**
     * Wait for any communication from client.
     * @return buffer : message received by the server
     */
    static char *wait_connection();

    /**
     * Close connection
     */
    static void close_connection();
};