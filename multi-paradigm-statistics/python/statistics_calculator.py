"""
This program demonstrates object-oriented programming in Python.
The StatisticsCalculator class encapsulates the dataset and the
behaviors used to calculate mean, median, and mode.
"""


class StatisticsCalculator:
    """
    This class groups state and behavior together.
    The dataset is stored in the object, and the calculations are
    implemented as methods that act on that stored data.
    """

    def __init__(self, data):
        self.data = data

    def mean(self):
        """Return the arithmetic mean as a float."""
        return sum(self.data) / len(self.data)

    def median(self):
        """
        Sort a copy of the data and return the middle value.
        This handles both odd-length and even-length datasets.
        """
        sorted_data = sorted(self.data)
        length = len(sorted_data)
        middle = length // 2

        if length % 2 == 0:
            return (sorted_data[middle - 1] + sorted_data[middle]) / 2
        return float(sorted_data[middle])

    def mode(self):
        """
        Return a list containing every mode.
        Using a method here highlights object-oriented design because
        the behavior belongs to the StatisticsCalculator object.
        """
        counts = {}
        for value in self.data:
            counts[value] = counts.get(value, 0) + 1

        highest_count = max(counts.values())
        return [value for value, count in sorted(counts.items()) if count == highest_count]

    def display_results(self):
        """Print results using the same format as the other language versions."""
        print("========================================")
        print("Statistics Calculator Demo")
        print("========================================")
        print(f"Data: {self.data}")
        print(f"Mean: {self.mean():.2f}")
        print(f"Median: {self.median():.2f}")
        print(f"Mode(s): {self.mode()}")


def main():
    fixed_data = [12, 6, 3, 6, 9, 15, 6, 3, 12]
    calculator = StatisticsCalculator(fixed_data)
    calculator.display_results()


if __name__ == "__main__":
    main()
