import ast

def secure_evaluate(user_input):
    try:
        # Safely evaluate only literals (e.g., numbers, strings, lists, etc.)
        result = ast.literal_eval(user_input)
        print("Evaluation Result:", result)
    except (ValueError, SyntaxError) as e:
        print("Invalid expression:", e)

if __name__ == "__main__":
    print("Enter a Python literal (e.g., 1 + 2 ❌, 'hello' ✅, [1, 2] ✅, {'a': 1} ✅):")
    user_input = input("> ")

    print("\nSecure evaluation:")
    secure_evaluate(user_input)

