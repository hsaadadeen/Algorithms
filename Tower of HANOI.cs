// assignment 7.40  13 April 2011
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Tower_of_HANOI
{
    class Program
    {
        /* Move: count disks from start to finish using temp as temporary storage.
        Pre: There are at least count disks on the tower start. The top disk(if anly) on each of towers temp and finish is larger than any of the top count
	        disks on tower start.
        Post: The top count disks on start have been moved to finish; temp(used for temorary storage) has been returned to its starting position.
        */

        void Move(int count, int start, int finish, int temp)
        {
            if (count > 0)
            {
                Move(count - 1, start, temp, finish);
                Console.WriteLine("Move a disk from {0} to {1}.", start, finish);
                Move(count - 1, temp, finish, start);
            }	// end if

        }	// end function Move

        static void Main(string[] args)
        {
            // prompt user and read input
            Console.Write("Enter number of disks: ");
            int Disks = Convert.ToInt32(Console.ReadLine());

            Program test = new Program();

            test.Move(Disks, 1, 3, 2);

        } // end method main
    } // end class Program
}
