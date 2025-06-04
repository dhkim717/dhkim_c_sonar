def insecure_evaluate(user_input):
    try:
        # Insecurely evaluate the user input using eval
        result = eval(user_input)
        print("Evaluation Result:", result)
    except Exception as e:
        print("Error:", e)

if __name__ == "__main__":
    print("Enter a Python expression (e.g., 1 + 2, 'hello'.upper(), [1, 2] * 3):")
    user_input = input("> ")

    # Warning: This approach is insecure
    print("\nInsecure evaluation:")
    insecure_evaluate(user_input)

