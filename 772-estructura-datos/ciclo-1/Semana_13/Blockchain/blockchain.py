import hashlib
import json
import time

class Blockchain:
    def __init__(self):
        self.chain = []
        self.transactions = []

        self.create_block("0")

    def create_block(self, previous_hash):
        block = {
            "info": {
                "index": len(self.chain) + 1,
                "timestamp": time.time(),
                "transactions": self.transactions
            },
            "previous_hash": previous_hash,
            "hash": None
        }
        block["hash"] = self.hash(block["info"])
        self.transactions = []
        self.chain.append(block)

        return block
    
    def add_transaction(self, sender, reciever, amount):
        transaction = {
            "sender": sender,
            "reciever": reciever,
            "amount": amount
        }
        self.transactions.append(transaction)
    
    def hash(self, info):
        string = json.dumps(info, sort_keys=True).encode()
        return hashlib.sha256(string).hexdigest()
        
    def is_valid_chain(self):
        for i in range(1, len(self.chain)):
            current = self.chain[i]
            previous = self.chain[i-1]

            if current["hash"] != self.hash(current["info"]):
                return False
            
            if current["previous_hash"] != previous["hash"]:
                return False
        return True
