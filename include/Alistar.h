/*
** Alistar.h for proto in /home/thieba_r/Documents/prototype
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Tue Jun 16 19:40:50 2015 Raphael Thiebault
** Last update Fri Jun 19 15:33:50 2015 Raphael Thiebault
*/

#ifndef		ALISTAR_H_
# define	ALISTAR_H_

class	Node;
class	AStarSearch;

class	MapSearchNode
{
 public:
  int	x;
  int	y;

  MapSearchNode();
  MapSearchNode(int px, int py);
  float	GoalDistanceEstimate(MapSearchNode&);
  float	GetCost(MapSearchNode&);
  int	GetMap();
  int	GetMap(int, int);
  void	PrintNodeInfo();
  Node	*Collision(Node*, Node*);
  bool	Match(MapSearchNode&);
  bool	GetSuccessors(AStarSearch*, MapSearchNode*);
};

class	Node
{
 public:
  Node	*parent;
  Node	*child;
  float	g; // cost of this node + it's predecessors
  float	h; // heuristic estimate of distance to goal
  float	f; // sum of cumulative cost of predecessors and self and heuristic

  Node();
  MapSearchNode	Search;
};

class	HeapCompare_f
{
 public:
  bool	operator() (const Node *x, const Node *y) const;
};

class AStarSearch
{
 public:
   enum
   {
     SEARCH_STATE_NOT_INITIALISED,
     SEARCH_STATE_SEARCHING,
     SEARCH_STATE_SUCCEEDED,
     SEARCH_STATE_FAILED,
     SEARCH_STATE_OUT_OF_MEMORY,
     SEARCH_STATE_INVALID,
   };

   AStarSearch();
   void		CancelSearch();
   void		Setup(MapSearchNode&, MapSearchNode&);
   unsigned int	SearchStep();
   bool		Compare_f(Node*, Node*);
   bool		AddSuccessor(MapSearchNode&);
   void		FreeSolutionNodes();
   MapSearchNode	*GetSolutionStart();
   MapSearchNode	*GetSolutionEnd();
   MapSearchNode	*GetSolutionNext();
   MapSearchNode	*GetSolutionPrev();
   float	GetSolutionCost();
   int		GetStepCount();
 private:
   void		FreeAllNodes();
   void		FreeUnusedNodes();
   void		FreeNode(Node*);
   Node		*AllocateNode();

   unsigned int	m_State;
   int		m_Steps;
   Node		*m_Start;
   Node		*m_Goal;
   Node		*m_CurrentSolutionNode;
   std::vector<Node*>	m_OpenList;
   std::vector<Node*>	m_ClosedList;
   std::vector<Node*>	m_Successors;
};

class		AStarState
{
 public:
  virtual	~AStarState() {}
  virtual float	GoalDistanceEstimate(MapSearchNode&) = 0;
  virtual bool	GetSuccessors(AStarSearch*, MapSearchNode*) = 0;
  virtual float	GetCost(MapSearchNode&) = 0;
  virtual bool	Match(MapSearchNode&) = 0;
};

#endif		/* !ALISTAR_H_ */
