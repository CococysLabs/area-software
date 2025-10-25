from blockchain import Blockchain

def main():
    blockchain = Blockchain()

    blockchain.add_transaction("465", "485", "15000")
    blockchain.create_block(blockchain.chain[-1]["hash"])

    blockchain.add_transaction("133", "741", "50000")
    blockchain.add_transaction("133", "852", "75000")
    blockchain.add_transaction("133", "852", "5000")
    blockchain.create_block(blockchain.chain[-1]["hash"])

    blockchain.chain[1]["info"]["transactions"] = [1,2,3,4,5]

    for block in blockchain.chain:
        print("Bloque:")
        print(block)
        print("")

    print(blockchain.is_valid_chain())


if __name__ == "__main__":
    main()