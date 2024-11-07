// Specify the Solidity version
pragma solidity ^0.8.0;

// Define the StudentRegistry contract
contract StudentRegistry {

    // Define a structure 'Student' to store student data
    struct Student {
        string name;       // Name of the student
        uint rollNo;       // Roll number of the student
        string course;     // Course the student is enrolled in
    }

    // Array to store all student data
    Student[] public students;

    // Mapping from roll number to index in the students array
    // Used to efficiently fetch a student's data by roll number
    mapping(uint => uint) private rollNoToIndex;

    // Counter for the total number of students
    uint public studentCount;

    // Events to log actions in the contract
    event StudentAdded(string name, uint rollNo, string course);     // Triggered when a student is added
    event EtherReceived(address sender, uint amount);                // Triggered when Ether is received
    event FallbackTriggered(address sender, uint amount);            // Triggered for unexpected function calls

    // Function to add a new student to the registry
    function addStudent(string memory name, uint rollNo, string memory course) public {
        // Ensure that no student with the same roll number already exists
        require(rollNoToIndex[rollNo] == 0, "Student with this roll number already exists");

        // Add the new student to the students array
        students.push(Student(name, rollNo, course));

        // Store the index (index + 1 to differentiate from default 0 value)
        rollNoToIndex[rollNo] = students.length;

        // Increase the student count
        studentCount++;

        // Emit an event that a student has been added
        emit StudentAdded(name, rollNo, course);
    }

    // Function to get a student's details by roll number
    function getStudentByRollNo(uint rollNo) public view returns (string memory name, uint rollNoOut, string memory course) {
        // Fetch the index of the student from the mapping
        uint index = rollNoToIndex[rollNo];

        // Ensure that the student exists (index must be greater than 0)
        require(index > 0, "Student with this roll number does not exist");

        // Access the student data from the array (subtract 1 from index as the mapping stored index + 1)
        Student storage student = students[index - 1];

        // Return the student's data
        return (student.name, student.rollNo, student.course);
    }

    // Function to get the entire list of students
    function getAllStudents() public view returns (Student[] memory) {
        // Return the entire students array
        return students;
    }

    // Fallback function to handle calls with invalid function signatures
    // This function is triggered if someone sends Ether with no data or an invalid function call
    fallback() external payable {
        // Emit an event when the fallback function is triggered
        emit FallbackTriggered(msg.sender, msg.value);
    }

    // Receive function to accept Ether
    // This function is triggered when Ether is sent to the contract without data
    receive() external payable {
        // Emit an event when Ether is received by the contract
        emit EtherReceived(msg.sender, msg.value);
    }
}
