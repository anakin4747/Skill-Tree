from socket import *
import base64

msg = "\r\n I love computer networks!" 
endmsg = "\r\n.\r\n"

# Choose a mail server (e.g. Google mail server) and call it mailserver  

mailserver = "smtp.mailtrap.io"


# Create socket called clientSocket and establish a TCP connection with mailserver

serverPort = 587
clientSocket = socket(AF_INET, SOCK_STREAM)
# Create a socket that uses TCP/IP as indicated by
# the arguments AF_NET (IP) and SOCK_STREAM (TCP)
clientSocket.connect((mailserver, serverPort))
# Using the newly created socket, connect to the port
# serverPort, which is a socket in the mailserver


recv = clientSocket.recv(1024).decode()
# Recieve 1024 bytes of binary data from our client side socket
# decode the binary into UTF-8 to make it readable and save it in recv 
print("\nServer response to TCP connection: \n" + recv)
if recv[:3] != '220':
    # If recieved message is not what was expected
    # print, close TCP connection, and quit
    print('220 reply not received from server.')
    clientSocket.close()
    quit()


# Send HELO command and print server response. 

ehloCommand = 'EHLO smtp.mailtrap.io\r\n'
# Create an EHLO command with the format:
# EHLO <SP> domain <CRLF>
clientSocket.send(ehloCommand.encode())
# Encode command and send it out thought the client socket
recv = clientSocket.recv(1024).decode() 
# Recieve server's response, decode it, and save it
print("Server response to EHLO command: \n" + recv)
if recv[:3] != '250':
    print('250 reply not received from server.')
    clientSocket.close()
    quit()


authLogCmd = 'AUTH LOGIN\r\n'
# Create an AUTH LOGIN command with the format:
# AUTH LOGIN <CRLF>
clientSocket.send(authLogCmd.encode())
recv = clientSocket.recv(1024).decode() 
print("Server response to AUTH LOGIN command: \n" + recv[:4] + base64.b64decode(recv[3:]).decode() + '\n')
# Decode base64 encoding of Username 
if recv[:3] != '334':
    print('334 reply not received from server.')
    clientSocket.close()
    quit()


username = "f1b54cac14151b"
crlf = '\r\n'

clientSocket.send(base64.b64encode(username.encode()))
# encode the username into binary then encode the binary
# into base64 format to make sure data gets correctly transferred
clientSocket.send(crlf.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to Username input: \n" + recv[:4] + base64.b64decode(recv[3:]).decode() + '\n')
# Decode base64 encoding of Password 
if recv[:3] != '334':
    print('334 reply not received from server.')
    clientSocket.close()
    quit()

password = "c4e5da4b27be9a"

clientSocket.send(base64.b64encode(password.encode()))       
clientSocket.send(crlf.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to Password input: \n" + recv)
if recv[:3] != "235":
    print('235 Login: reply not received from server.')
    clientSocket.close()
    quit()


# Send MAIL FROM command and print server response.

mailFromCommand = 'MAIL FROM: <anakin@childerhose.ca>\r\n'
clientSocket.send(mailFromCommand.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to MAIL FROM command: \n" + recv)
if recv[:3] != '250':
    print('250 reply not received from server.')
    clientSocket.close()
    quit()


# Send RCPT TO command and print server response.

rcptToCommand = 'RCPT TO: <achilde@uwo.ca>\r\n'
clientSocket.send(rcptToCommand.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to RCPT TO command: \n" + recv)
if recv[:3] != '250':
    print('250 reply not received from server.')
    clientSocket.close()
    quit()


# Send DATA command and print server response.

dataCommand = 'DATA\r\n'
clientSocket.send(dataCommand.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to DATA command: \n" + recv)
if recv[:3] != '354':
    print('354 reply not received from server.')
    clientSocket.close()
    quit()


# Send message data.

clientSocket.send(msg.encode())


# Message ends with a single period.

clientSocket.send(endmsg.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to . command: \n" + recv)
if recv[:3] != '250':
    print('250 reply not received from server.')
    clientSocket.close()
    quit()


# Send QUIT command and get server response.

quitCommand = 'QUIT\r\n'
clientSocket.send(quitCommand.encode())
recv = clientSocket.recv(1024).decode()
print("Server response to QUIT command: \n" + recv)
if recv[:3] != '221':
    print('221 reply not received from server.')
    clientSocket.close()
    quit()

clientSocket.close()

