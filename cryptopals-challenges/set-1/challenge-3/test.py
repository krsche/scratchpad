import unittest
import python as c

class Test(unittest.TestCase):
    def test_duplicate_bytes(self):
        self.assertEqual(c.duplicate_bytes(b'a', 3), b'aaa')

if __name__ == '__main__':
    unittest.main()
