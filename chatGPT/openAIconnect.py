import openai

# token: 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

openai.api_key = "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"


def chat_with_chatgpt(prompt, model="gpt-3.5-turbo"):
    response = openai.Completion.create(
        engine="text-davinci-003",
        prompt=prompt,
        max_tokens=100,
        n=1,
        stop=None,
        temperature=0.5,
    )

    message = response.choices[0].text.strip()
    print(message)


if __name__ == "__main__":
    prompt = input("input the prompt\n")
    chat_with_chatgpt(prompt)
    while prompt != "byby":
        chat_with_chatgpt(prompt)
        prompt = input("type bellow:\n")
