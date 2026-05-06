# IdeaNest - Complete Page Index

**Total Screens: 15** (1 landing + 14 application pages)
**Total Files: 16** (14 HTML + 1 CSS + 1 README)

---

## 📑 Pages Directory

### Public Pages (No Login Required)

#### 1. **index.html** - Landing Page

- **URL:** Root directory
- **Purpose:** Marketing homepage for potential users
- **Key Sections:** Hero, Features, How It Works, CTA, Footer
- **Navigation:** Login/Sign Up buttons in navbar
- **Target Audience:** Visitors discovering the platform

---

### Authentication Pages

#### 2. **pages/login.html** - User Login

- **Purpose:** Authenticate existing users
- **Features:** Email login, Google OAuth, Remember me, Forgot password link
- **Layout:** Split (blue gradient left, white right)
- **Next Step:** Redirects to dashboard based on role
- **Target:** Returning users

#### 3. **pages/signup.html** - New User Registration

- **Purpose:** Create new user accounts
- **Requirements:** Gmail-only email, Age 18+, Password confirmation
- **Features:** Password strength indicator, Terms acceptance
- **Next Step:** Redirects to profile-setup.html
- **Target:** New users

---

### Profile Configuration

#### 4. **pages/profile-setup.html** - Complete Profile

- **Purpose:** Configure user profile after signup
- **Mandatory:** Role selection, Skills/interests
- **Optional:** Bio, Photo
- **Critical Feature:** Skip option with restrictions warning
- **Next Step:** Redirects to role-based dashboard
- **Decision Point:** Unlock features vs. Limited access

---

### Role-Based Dashboards

#### 5. **pages/founder-dashboard.html** - Founder Main Hub

- **Role:** Founder (can switch to Investor if eligible)
- **Content:** Statistics, action cards, recent ideas list
- **Navigation:** Dashboard, Submit Idea, Submit Startup, My Ideas, Messages, Settings
- **Features:** Role switcher dropdown, Quick stats (4 cards)
- **CTA Buttons:** Share Idea, Seek Funding, Connect with Users
- **Mixed Content Display:** Shows both idea review and investment posts

#### 6. **pages/advisor-dashboard.html** - Advisor Review Hub

- **Role:** Advisor (can switch to Investor if eligible)
- **Content:** Review statistics, filterable idea list, ratings
- **Filters:** Category, Sort By, Priority
- **Important:** Shows ONLY "Idea Review" posts, NOT investment posts
- **Features:** Star ratings, priority badges, review count
- **Navigation:** Dashboard, Browse Ideas, My Reviews, Messages, Settings

#### 7. **pages/investor-dashboard.html** - Investor Portfolio Hub

- **Role:** Investor (can switch to Founder or Advisor if eligible)
- **Content:** Portfolio stats, startup browsing, investment tracking
- **Filters:** Industry, Funding Stage, Budget Range
- **Important:** Shows ONLY "Investment Posts," NOT idea review posts
- **Features:** Grid/List view toggle, traction metrics, watch button, save startup
- **Startup Cards:** Logo, name, tagline, team info, metrics, funding stage badge
- **Navigation:** Dashboard, Browse Startups, Portfolio, Saved, Messages, Settings

---

### Submission Forms - Separate Flows

#### 8. **pages/founder-submit-idea.html** - Idea Review Form

- **Post Type:** "Idea Review" (seeking feedback, NO funding)
- **Audience:** Advisors only (invisible to investors)
- **Mode Badge:** Blue "💡 Idea Review Mode"
- **Unique Feature:** Comparison table showing differences from Investment mode
- **Form Sections:** Basic info, Problem, Solution, Additional details, Feedback preferences
- **Fields:** Title, Category, Problem (500 chars), Solution (500 chars), Target Audience, Key Features, Full Description (1000 chars), Feedback type checkboxes, File attachments
- **Character Counter:** Real-time display for text fields
- **Design:** Non-funding focused, feedback-emphasis layout

#### 9. **pages/founder-submit-startup.html** - Startup Investment Form

- **Post Type:** "Investment Post" (seeking FUNDING)
- **Audience:** Investors only (invisible to advisors)
- **Mode Badge:** Green "💰 Investment Mode"
- **Progress Indicator:** 3-step visualization
- **Form Sections:** Company Info, Funding Requirements, Business Plan
- **Fields:** Company name, tagline, industry, founded date, team size, funding amount, funding stage (Seed/Series A/B/C+), use of funds, equity offered, market size, business model, traction, competitive advantage, financial projections file, business plan/pitch deck file, contact info
- **Finance Focus:** Funding amounts, equity, business metrics emphasis
- **Design:** Investment-focused, business planning emphasis

#### 10. **pages/founder-ideas.html** - My Ideas & Startups

- **Purpose:** View founder's submitted ideas and startups
- **Tabs:** All Posts (3), Ideas (1), Startups (2), Drafts (0)
- **Filters:** Type, Status, Sort By
- **Card Layout:** Title, type badge, metadata, description, stats (views, ratings, feedback), actions
- **Status Indicators:** Published, Draft, Closed
- **Actions Per Card:** View, Edit, Close
- **Pagination:** Previous/Next navigation

---

### Content Viewing & Interaction

#### 11. **pages/idea-details.html** - Idea View & Feedback

- **Purpose:** Display full idea with feedback system
- **Content Layout:** 2-column (main + sidebar)
- **Main Content:** Problem, solution, features, USP, description, traction
- **Feedback Section:** List of advisor feedback (8+ items), star ratings, timestamps, text comments
- **Feedback Form:** Star rating input, textarea for response, character counter
- **Sidebar Widgets:**
  - Ratings display (4.5⭐/5 with count)
  - Feedback categories breakdown
  - Action buttons (Message, Save, Share)
  - Status info (Type, Status, Category)
- **Interactive:** Click-to-rate stars, form submission simulation
- **Responsive:** 2-column desktop → 1-column mobile

#### 12. **pages/startup-details.html** - Startup View & Investment Details

- **Purpose:** Display comprehensive startup information for investors
- **Header Section:** Logo, name, tagline, team info, funding stage
- **Main Sections:** Traction metrics, business model, market opportunity, use of funds, team bios
- **Traction Display:** 3-card grid (users, MRR, growth %)
- **Team Section:** Founder bios with previous experience
- **Fund Allocation:** Visual breakdown (40% engineering, 30% marketing, etc.)
- **Materials:** Downloadable pitch deck, financial projections, business plan
- **Sidebar:**
  - Funding details (amount, equity %)
  - Investment requirements (accredited, lock-up period, board seat)
  - Founder contact card
  - Status (funding progress, post date)
- **CTA:** Contact Founder button, Save Startup, View Full Metrics

---

### Messaging & Communication

#### 13. **pages/chat.html** - Real-Time Chat System

- **Layout:** 3-column (sidebar + conversation list + message window)
- **Conversation List:** Search input, list of chats with avatars, names, previews, timestamps
- **Active State:** Blue highlight on selected conversation
- **Chat Window:**
  - Header with user name & online status
  - Call/video/options buttons
  - Message bubbles (sent=blue/right, received=white/left)
  - Timestamps on each message
  - Input area with attach file & send button
- **Interactive:** Type-to-send on Enter, simulated message sending
- **Use Cases:** Founder↔Advisor, Founder↔Investor conversations
- **Responsive:** Hides conversation list on mobile

---

### Settings & Configuration

#### 14. **pages/settings.html** - User Settings

- **Tab 1: Account Settings**
  - Profile picture upload
  - First/Last name, Bio, Location, Website
  - Role & Skills management
  - Password change
  - Danger zone (delete account)
- **Tab 2: Privacy & Safety**
  - Profile visibility (Public/Private)
  - Who can contact settings (Advisors, Investors, Founders)
  - Data & analytics preferences
- **Tab 3: Notifications**
  - Email notification toggles (Feedback, Investor Interest, Messages, Digest, Features, Marketing)
- **Tab 4: Preferences**
  - Theme selection (Light/Dark/System)
  - Language & Timezone
  - Content preferences
  - API access key management
- **Design:** Tab navigation, toggle switches, form groups
- **Interactive:** Tab switching, toggle activation

---

### Administrative

#### 15. **pages/admin-panel.html** - Admin Dashboard

- **Role:** Administrator (🔐 badge)
- **Stats Section:** 4 cards (Total Users, Pending Verification, Total Ideas, Active Reports)
- **User Verification Table:**
  - Columns: User (name/email/avatar), Role, Submitted date, Status badge, Actions
  - Status badges: Pending (yellow), Approved (green), Rejected (red)
  - Sample users: 4 entries with mixed statuses
  - Action buttons: Review, Details
- **Reports & Moderation:**
  - Alert banner: "8 active reports require review"
  - 3+ report items showing: ID, reporter, target, reason tag, action buttons
  - Actions: Review Report, Remove Content, Ban User
- **Platform Statistics:**
  - User breakdown (Founders, Investors, Advisors counts)
  - Content stats (Ideas, Startups, Feedback counts)
  - Engagement metrics (active users, daily avg, messages)
- **Navigation:** Dashboard, User Verification, Reports, Users, Ideas & Startups, Settings, Logout

---

## 🎨 Styling & Assets

#### **assets/styles.css** - Global Design System

- **Lines:** 800+
- **Contains:**
  - Color palette (8 main colors + utilities)
  - Typography hierarchy
  - Button styles (6 variants)
  - Card components
  - Form styling
  - Navigation (navbar, sidebar)
  - Layout utilities (grid, flex, spacing)
  - Alerts & badges
  - Modals
  - Chat styles
  - Responsive media queries (@768px, @1024px)
  - No external dependencies
- **Used By:** All 14 HTML pages

---

## 📊 Navigation Flow Chart

```
Landing (index.html)
  ├─ Sign Up (signup.html)
  │   └─ Profile Setup (profile-setup.html) [Locked if skipped]
  │       ├─ Founder Dashboard (founder-dashboard.html)
  │       ├─ Advisor Dashboard (advisor-dashboard.html)
  │       └─ Investor Dashboard (investor-dashboard.html)
  │
  └─ Login (login.html)
      ├─ Founder Dashboard
      │   ├─ Submit Idea (founder-submit-idea.html)
      │   ├─ Submit Startup (founder-submit-startup.html)
      │   ├─ My Ideas (founder-ideas.html)
      │   └─ Idea Details (idea-details.html)
      │
      ├─ Advisor Dashboard
      │   └─ Idea Details (idea-details.html)
      │
      └─ Investor Dashboard
          ├─ Startup Details (startup-details.html)
          └─ Idea Details (idea-details.html) [Optional]

All Roles:
  ├─ Chat (chat.html)
  ├─ Settings (settings.html)
  └─ Admin Panel (admin-panel.html) [Admin only]
```

---

## 🔒 Access Control Matrix

| Page                        | Public | Founder | Advisor | Investor | Admin |
| --------------------------- | ------ | ------- | ------- | -------- | ----- |
| index.html                  | ✅     | ✅      | ✅      | ✅       | ✅    |
| login.html                  | ✅     | -       | -       | -        | -     |
| signup.html                 | ✅     | -       | -       | -        | -     |
| profile-setup.html          | ❌     | ✅      | ✅      | ✅       | -     |
| founder-dashboard.html      | ❌     | ✅      | ❌      | ❌       | -     |
| advisor-dashboard.html      | ❌     | ❌      | ✅      | ❌       | -     |
| investor-dashboard.html     | ❌     | ❌      | ❌      | ✅       | -     |
| founder-submit-idea.html    | ❌     | ✅      | ❌      | ❌       | -     |
| founder-submit-startup.html | ❌     | ✅      | ❌      | ❌       | -     |
| founder-ideas.html          | ❌     | ✅      | ❌      | ❌       | -     |
| idea-details.html           | ❌     | ✅      | ✅      | ✅       | -     |
| startup-details.html        | ❌     | ✅      | ❌      | ✅       | -     |
| chat.html                   | ❌     | ✅      | ✅      | ✅       | ✅    |
| settings.html               | ❌     | ✅      | ✅      | ✅       | ✅    |
| admin-panel.html            | ❌     | ❌      | ❌      | ❌       | ✅    |

---

## 💾 File Structure

```
IdeaNest/
├── index.html                           (Landing page - public)
├── README.md                            (Documentation)
├── assets/
│   └── styles.css                       (Global design system)
└── pages/
    ├── login.html                       (Authentication)
    ├── signup.html                      (Registration)
    ├── profile-setup.html               (Profile completion)
    ├── founder-dashboard.html           (Founder main hub)
    ├── founder-submit-idea.html         (Idea review form)
    ├── founder-submit-startup.html      (Investment form)
    ├── founder-ideas.html               (Founder's submissions)
    ├── advisor-dashboard.html           (Advisor main hub)
    ├── investor-dashboard.html          (Investor main hub)
    ├── idea-details.html                (Idea view with feedback)
    ├── startup-details.html             (Startup investment view)
    ├── chat.html                        (Messaging system)
    ├── settings.html                    (User configuration)
    └── admin-panel.html                 (Admin moderation)
```

---

## 🚀 Quick Navigation

### For Users Who Want To...

**Submit an Idea for Feedback:**

1. Start → Founder Dashboard
2. Click "Submit Idea (Review)"
3. Fill founder-submit-idea.html form
4. Idea appears in Advisor Dashboard

**Seek Startup Funding:**

1. Start → Founder Dashboard
2. Click "Submit Startup (Funding)"
3. Fill founder-submit-startup.html form
4. Startup appears in Investor Dashboard

**Review Ideas as Advisor:**

1. Start → Advisor Dashboard
2. Browse idea list (filtered by category, priority)
3. Click "Review" → idea-details.html
4. Add star rating & feedback

**Browse Startups as Investor:**

1. Start → Investor Dashboard
2. Filter by industry, stage, budget
3. Click "View Details" → startup-details.html
4. Click "Contact Founder" → chat.html

**Message Other Users:**

1. From any dashboard
2. Click "Messages" → chat.html
3. Select conversation or start new

**Manage Profile:**

1. From any dashboard
2. Click "Settings" → settings.html
3. Update profile, privacy, notifications

---

## 📱 Responsive Features

All pages are fully responsive with:

- **Desktop:** Full 2-3 column layouts
- **Tablet (768px+):** Adjusted spacing, sidebar hides/shows based on content
- **Mobile (<768px):** Single column, full-width buttons, hidden sidebar

---

## ✨ Implemented Features Summary

✅ Complete SaaS platform UI (15 pages)
✅ Strict role-based access (Founder+Investor, Advisor+Investor only)
✅ Two distinct submission flows (Idea Review vs. Investment Post)
✅ Advisor sees ONLY idea review posts
✅ Investor sees ONLY investment posts
✅ Dynamic role switching with UI adaptation
✅ Profile completion with access restrictions
✅ Messenger-style real-time chat
✅ Admin moderation interface
✅ Comprehensive settings page
✅ Global design system (no external libraries)
✅ Responsive mobile design
✅ Interactive form validation
✅ Star rating system
✅ File download simulation
✅ Tab-based navigation
✅ Toggle switches & checkboxes
✅ Filter & sort systems
✅ Pagination controls
✅ Status indicators & badges
✅ Search functionality
✅ Ready for Figma import

---

**Version:** 1.0 (Complete)
**Last Updated:** 2024
**Browser Support:** Chrome, Safari, Firefox, Edge (all modern versions)
**Accessibility:** Semantic HTML, WCAG guidelines followed
**Design Inspiration:** Notion, Stripe, Figma - modern SaaS design patterns
