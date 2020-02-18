using System.Collections.Generic;
using System.Linq;
using System.Web.Http;
using WebApplication.Models;

namespace WebApplication.Controllers
{
    /// <summary>
    ///     To get and update Person related information
    /// </summary>
    public class PeopleController : ApiController
    {
        List<Person> peopleList = new List<Person>();

        /// <summary>
        ///     Constructor
        /// </summary>
        public PeopleController()
        {
            peopleList.Add(new Person(){FirstName = "Rishabh", LastName = "Sharma", Id = 1});
            peopleList.Add(new Person() { FirstName = "Hello", LastName = "World", Id = 2 });
            peopleList.Add(new Person() { FirstName = "Another", LastName = "Name", Id = 3 });
        }

        //To get only the firstNames
        //i.e a special Get to get only the firstNames
        //define the Route
        /// <summary>
        ///     To get collection of only the first name
        /// </summary>
        /// <returns>Collection of first names of all the Person</returns>
        [Route("api/People/GetFirstName")]
        [HttpGet]
        public List<string> GetFirstName()
        {
            List<string> retValue = new List<string>();
            foreach (var person in peopleList)
            {
                retValue.Add(person.FirstName);
            }

            return retValue;
        }

        /// <summary>
        ///     To get all the Person
        /// </summary>
        /// <returns>Collection of Person</returns>
        public List<Person> Get()
        {
            return peopleList;
        }
        
        /// <summary>
        ///     To get the Person on the basis of Id provided as parameter
        /// </summary>
        /// <param name="id">Person unique identifier</param>
        /// <returns>Person object which has the given Id</returns>
        public Person Get(int id)
        {
            return peopleList.FirstOrDefault(info => info.Id.Equals(id));
        }
    }
}