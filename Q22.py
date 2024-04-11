import re

class PlagiarismChecker:
    def __init__(self):
        self.hash_table = {}

    def add_document(self, document):
        for word in re.split("\W+", document):
            if word not in self.hash_table:
                self.hash_table[word] = []
            self.hash_table[word].append(document)

    def check_for_plagiarism(self, document):
        for word in re.split("\W+", document):
            if word in self.hash_table:
                for other_document in self.hash_table[word]:
                    if other_document != document:
                        print("Found plagiarism:", document, "copied from", other_document)

if __name__ == "__main__":
    plagiarism_checker = PlagiarismChecker()

    plagiarism_checker.add_document("This is the first document.")
    plagiarism_checker.add_document("This is the second document.")

    plagiarism_checker.check_for_plagiarism("This is the first document.")
    plagiarism_checker.check_for_plagiarism("This is the second document.")