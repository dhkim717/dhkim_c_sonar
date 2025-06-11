
# 1. Secure Command Execution
import subprocess

# Secure: Use subprocess with a list of arguments and validate input
user_input = input("Enter filename to list: ")
if user_input.isalnum():  # Simple validation: only allow alphanumeric filenames
    subprocess.run(["ls", user_input])
else:
    print("Invalid input.")

# 2. Secure Deserialization
import json

# Secure: Use JSON instead of pickle and only with trusted data
data = input("Enter JSON data: ")
try:
    obj = json.loads(data)  # Safer alternative to pickle
    print("Parsed object:", obj)
except json.JSONDecodeError:
    print("Invalid JSON data.")

# 3. Secure SQL Execution
import sqlite3

# Secure: Use parameterized queries to prevent SQL injection
conn = sqlite3.connect('users.db')
cursor = conn.cursor()
username = input("Username: ")
password = input("Password: ")

query = "SELECT * FROM users WHERE username = ? AND password = ?"
cursor.execute(query, (username, password))  # Safe: parameterized query
result = cursor.fetchall()
print("Query result:", result)

# 4. Secure File Access
import os

# Secure: Validate and sanitize filename to prevent path traversal
filename = input("Enter filename to read: ")
base_path = "./uploads/"
safe_path = os.path.abspath(os.path.join(base_path, filename))

if safe_path.startswith(os.path.abspath(base_path)):
    try:
        with open(safe_path, "r") as f:
            content = f.read()
            print(content)
    except FileNotFoundError:
        print("File not found.")
else:
    print("Invalid filename.")

# 5. Secure Secret Handling
import os

# Secure: Load secrets from environment variables
API_KEY = os.getenv("API_KEY", "default_api_key")  # Default value for development

def charge_card():
    print("Charging card using secure API key.")  # Do not print the actual key
