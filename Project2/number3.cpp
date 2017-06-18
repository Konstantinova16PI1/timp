#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <memory.h>
#include <unistd.h>
#include <string>
#include <errno.h>
#include <iostream>

using namespace std;

class Ceaser
{
private:
  int key;class Ceaser
{
private:
  int key;

public:
  Ceaser(int key);
  std::string decrypt(std::string values);
  std::string encrypt(std::string values);
};

Ceaser::Ceaser(int key)
{
  this->key = key;

};

string Ceaser::encrypt(std::string values)
{


  for (int i = 0; i < values.size(); i++)
  {
    if ((values[i] >= 'a') && (values[i] <= 'z'))
    {
      if (values[i] >= ('z' - key))
      {
        values[i] = values[i] - 26 + key;
      }
      else values[i] = values[i] + key;
    }
    else if ((values[i] >= 'A') && (values[i] <= 'Z'))
    {
      if (values[i] >= ('Z' - key))
      {
        values[i] = values[i] - 26 + key;
      }
      else values[i] = values[i] + key;
    }
  }
      return values;
};

string Ceaser::decrypt(std::string values)
{

  for (int i = 0; i < values.size(); i++)
  {
    if (((values[i] >= 'a') && (values[i] <= 'z')) || ((values[i] >= 'A') && (values[i] <= 'Z')))
		{
			if ((values[i] >= 'a') && (values[i] <= 'z'))
			{
				if (values[i] <= ('a' + key))
				{
					values[i] = values[i] + 26 - key;
				}
				else values[i] = values[i] - key;
			}
			if ((values[i] >= 'A') && (values[i] <= 'Z'))
			{
				if (values[i] <= ('A' + key))
				{
					values[i] = values[i] + 26 - key;
				}
				else values[i] = values[i] - key;
			}
    }
    return values;

  }
}

class Replace
{
private:
  int range;
  std::string key;
  std::string abc = "abcdefghijklmnopqrstuvwxyz";

public:
  Replace(std::string key);
  std::string encrypt(std::string values);
  std::string decrypt(std::string values);
};
Replace::Replace(std::string key)
{
    this->key=key;
}
string Replace::encrypt(std::string values)
{

  for (int i = 0; i < values.size(); i++)
  {
    for (int j = 0; j < abc.size(); j++)
    {
      if (values[i] == abc[j])
      {
        values[i] = key[j];
        break;
      }
      // Capital letters
      else if ((values[i] - 32) == abc[j])
      {
        values[i] = key[j] + 32;
      }
    }
  }
  return values;

};

string Replace::decrypt(std::string values)
{
  for (int i = 0; i < values.size(); i++)
  {
    for (int j = 0; j < abc.size(); j++)
    {
      if (values[i]  == key[j])
      {
        values[i] = abc[j] ;
        break;
      }
      // Capital letters
      else if ((values[i]-32) == key[j])
      {
        values[i] = abc[j] + 32;
        break;
      }
    }
  }
  return values;

};

class Server
{
private:
  int init_socket, client_socket;
  sockaddr_in *client_addr, *server_addr;
  int rc;
  void setup_server();
  void lisening();
  void process();



public:
  Server();
  int send_string(string switch_str);
  string get_string();
};

Server::Server()
{
  // Иницилизация сокета
  this->init_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (this->init_socket == -1)
  {
    perror("Error");
    exit(1);
  }
  setup_server();

  lisening();

  close(this->init_socket);
};

// Параметры сервера

void Server::setup_server()
{
    server_addr = new (sockaddr_in);
    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(4747);
    server_addr->sin_addr.s_addr = htonl((127<<24)+1); // 127.0.0.1 - LOCALHOST
    rc=bind(this->init_socket,(const sockaddr*)server_addr,sizeof(sockaddr_in));

    if (rc == -1)
    {
      perror("Error");
      exit(2);
    }

    rc = listen(this->init_socket, 25);
    if (rc == -1)
    {
      perror("Error");
      exit(3);
    }
};

// Режим прослушивания

void Server::lisening()
{
  while(true)
  {
    client_addr = new (sockaddr_in);
    socklen_t addrlen=sizeof (sockaddr_in);
    this->client_socket = accept(this->init_socket,(struct sockaddr*)client_addr,&addrlen);

    process();


    if (client_socket == -1)
    {
      perror("[err] Error binding on server side: ");
      exit(4);
    }
  }
};

int Server::send_string(string switch_str)
{
  return send(client_socket,(const void*)switch_str.data(),switch_str.size(),0);
};

string Server::get_string()
{
  char * buffer = new char[257];
  int rc = recv(client_socket, (void*)buffer, 256, 0);
  if (buffer[0] == '\n')
      return string();
  if (rc == -1 )
  {
    perror("Error");
    exit(5);
  }
  return string(buffer);
};

void Server::process()
{



    string switch_str, str;
    string dict;
    int key;

    send_string( "EN/DE CRYPT \n" );
    switch_str = get_string();

    switch (switch_str[0]) {
      case 'e':
      {
        send_string( "CEASER/REPLACE" );
        switch_str = get_string();


        switch (switch_str[0]) {
          case 'c':
          {
            send_string( "STRING" );
             str = get_string();
            send_string( "KEY" );
             key = atoi(get_string().c_str());

            Ceaser m(key);
            send_string( m.encrypt(str) );
            break;
          }
          case 'r':
          {
            send_string( "STRING" );
             str = get_string();
            send_string( "KEY" );
             dict = get_string();

            Replace n(dict);
            send_string(  n.encrypt(str) );
          }
        }
        break;
      }
      case 'd':
      {
        send_string( "CEASER/REPLACE" );
        switch_str = get_string();

        switch (switch_str[0]) {
        case 'c':
        {
          send_string( "STRING" );
           str = get_string();
          send_string( "KEY" );
           key = atoi(get_string().c_str());

          Ceaser k(key);
          send_string( k.decrypt(str) );
          break;
        }
        case 'r':
        {
          send_string( "STRING" );
           str = get_string();
          send_string( "KEY" );
           dict = get_string();

          Replace l(dict);
          send_string( l.decrypt(str) );
          break;
        }
        break;
      }
      break;
      }
    }


  close(client_socket);


};

int main(int argc, char ** argv)
{
  Server server;

  return 0;
}
