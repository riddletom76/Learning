using System.Collections.Generic;
using Commander.Models;

namespace Commander.Data
{
    public class MockCommanderRepo : ICommanderRepo
    {
        List<Command> Commands;
        public MockCommanderRepo()
        {
            Commands = new List<Command>{
                new Command{Id=0, HowTo = "Ride a Bike", Line="Mock Line 0", Platform = "Mock Platform 0"},
                new Command{Id=1, HowTo = "Ride a Bike", Line="Mock Line 1", Platform = "Mock Platform 1"},
                new Command{Id=2, HowTo = "Ride a Bike", Line="Mock Line 2", Platform = "Mock Platform 2"}
            };
        }
        public IEnumerable<Command> GetAllCommands()
        {            
            return Commands;
        }

        public Command GetCommandById(int id)
        {
            return Commands[id];
        }
    }
}