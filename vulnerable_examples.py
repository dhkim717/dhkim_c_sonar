
# 1. Command Injection
import os

# Vulnerability: User input is passed directly to the shell command without sanitization
user_input = input("Enter filename to list: ")
os.system(f"ls {user_input}")  # Dangerous: susceptible to command injection
# if input "; rm -rf /"

# 2. Insecure Deserialization
import pickle

# Vulnerability: Untrusted input is deserialized using pickle, which can execute arbitrary code
data = input("Enter pickled data: ")
obj = pickle.loads(data)  # Dangerous: can lead to remote code execution

# 3. SQL Injection
import sqlite3

# Vulnerability: User input is used to construct an SQL query directly
conn = sqlite3.connect('users.db')
username = input("Username: ")
password = input("Password: ")

query = f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'"
conn.execute(query)  # Dangerous: susceptible to SQL injection

#input ' OR '1'='1 

# 4. Path Traversal
# Vulnerability: User input is used to construct a file path without validation
filename = input("Enter filename to read: ")
with open(f"./uploads/{filename}", "r") as f:
    content = f.read()  # Dangerous: can allow directory traversal attacks

#input: ../../etc/passwd 

# 5. Hardcoded Secrets
# Vulnerability: Sensitive information is hardcoded in the source code
API_KEY = "sk_test_abc123XYZ"

def charge_card():
    print(f"Using API key: {API_KEY}")  # Dangerous: secrets should not be hardcoded
